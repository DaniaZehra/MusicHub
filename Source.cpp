#include <fstream>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/access.hpp>

using namespace std;
class Song {

};

class User {
public:
    string username;
    string password;

    // Default constructor
    User() {}

    // Parameterized constructor
    User(string a, string b) : username(a), password(b) {}

private:
    // Serialization function
    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& username;
        ar& password;
    }
public:
    void SignUp() {
        //Serialization
        {
            std::ofstream ofs("user_data.txt");
            boost::archive::text_oarchive oarchive(ofs);

            User user1("john_doe", "password123");
            User user2("alice", "secure_pass");

            oarchive << user1 << user2;

            cout << "User data serialized successfully." << endl;
        }
    }
    void Login() {
        {
            std::ifstream ifs("user_data.txt");
            boost::archive::text_iarchive iarchive(ifs);

            try {
                while (true) {
                    User loadedUser;
                    iarchive >> loadedUser;
                    if (loadedUser.username == username && loadedUser.password == password) {
                        cout << "Login Successful!" << endl;
                        break;
                    }
                }
            }
            catch (const boost::archive::archive_exception& e) {
                if (e.code == boost::archive::archive_exception::input_stream_error) {
                    cout << "End of file reached." << endl;
                }
                else {
                    cerr << "Error during deserialization: " << e.what() << endl;
                }
            }
        }
    }
};

int main() {
    User u2("john_doe", "password123");
    u2.Login();
}

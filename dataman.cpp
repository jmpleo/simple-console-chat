#include "dataman.h"
#include <vector>

DataManager::DataManager() {}
DataManager::~DataManager() {}

void DataManager::Authentication(const std::string &username,
                                 const std::string &password) {
    if (usersRecords_[username] != password) {
        throw DataManagerException("[error]: wrong password");
    }
}

void DataManager::Registration(const std::string &username,
                               const std::string &password) {
    if (usersRecords_[username].empty()) {
        usersRecords_[username] = password;

    } else {
        throw DataManagerException("[error]: username not available");
    }
}

void DataManager::SendMessage(const std::string& sender,
                              const std::string& reciepient,
                              const std::string& message) {
    if (usersRecords_[reciepient].empty()) {
        throw DataManagerException("[error]: reciepient does not exist");

    } else {
        usersInbox_[reciepient].push_back("from: " + sender + "\n" + message);
    }
}

void DataManager::SendMessage(const std::string& sender,
                              const std::string& message) {
    for (auto userBox : usersInbox_) {
        userBox.second.push_back("from: " + sender + "\n" + message);
    }
}

std::vector<std::string>::reverse_iterator
DataManager::GetBeginMessage(const std::string &username) { return usersInbox_[username].rbegin(); }

std::vector<std::string>::reverse_iterator
DataManager::GetEndMessage(const std::string &username) { return usersInbox_[username].rend(); }


# Voice of Power Web App - Software Architecture Design

## High-Level Architecture
- **User Interface (UI)**: The front end of the application where users interact with the system.
- **Backend Services**: Handles business logic, authentication, file processing, and interaction with databases and third-party services.
- **Database**: Stores user data, uploaded files, preferences, and logs.
- **File Storage**: Manages the storage of uploaded PDF files and generated audio files.
- **Third-Party Services**: Integrates Text-to-Speech (TTS) services.

## UML Diagrams

### Use Case Diagram
```puml
@startuml
actor User
User --> (Register)
User --> (Login)
User --> (Upload File)
User --> (Convert Text-to-Speech)
User --> (Play Audio)
User --> (Manage Files)
User --> (Update Preferences)
@enduml



##Class Diagram
@startuml
class User {
  +id: String
  +username: String
  +password: String
  +email: String
  +preferences: Settings
}

class File {
  +id: String
  +userId: String
  +fileName: String
  +filePath: String
  +status: String
}

class TTSProcessor {
  +convert(file: File): AudioFile
}

class AudioPlayer {
  +play(audioFile: AudioFile)
}

class Settings {
  +language: String
  +readingSpeed: String
  +voice: String
}

class AuthService {
  +register(user: User)
  +login(username: String, password: String): User
}

class FileService {
  +upload(file: File)
  +getFiles(userId: String): List<File>
}

class TTSService {
  +convertTextToSpeech(file: File): AudioFile
}

class AudioService {
  +playAudio(audioFile: AudioFile)
}

class SettingsService {
  +updateSettings(userId: String, settings: Settings)
}

User "1" --> "1..*" File
User "1" --> "1" Settings
File "1" --> "1" TTSProcessor
File "1" --> "1" AudioPlayer
AuthService "1" --> "1" User
FileService "1" --> "1..*" File
TTSService "1" --> "1" TTSProcessor
AudioService "1" --> "1" AudioPlayer
SettingsService "1" --> "1" Settings
@enduml


##Sequence Diagram for User Registration

@startuml
actor User
User -> UI: Open Registration Form
User -> UI: Enter Details
User -> Backend: Submit Registration Form
Backend -> AuthService: Register User
AuthService -> Database: Save User Details
Database -> AuthService: Confirmation
AuthService -> Backend: User Registered
Backend -> UI: Show Success Message
@enduml


##Activity Diagram for File Upload Process

@startuml
start
:Select File;
:Validate File;
if (File is Valid?) then (yes)
  :Upload File;
  :Store File in S3/MinIO;
  :Update Database;
  :Upload Successful;
else (no)
  :Show Error;
endif
stop
@enduml


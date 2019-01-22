<img src="https://github.com/yodellabs/ALPS-Framework-iOS/blob/master/docs/logo.png" width="320">

# ALPS-Framework-iOS
The Acoustic Location Processing System (ALPS) framework provides indoor localization services to iOS devices. ALPS uses time-of-flight ranging from ultrasound beacons at known locations to determine the location of the mobile device.

Documentation for the API of the framework can be found here: https://yodellabs.github.io/ALPS-Framework-iOS/

## Adding ALPS to your XCode Project

1. Create a new Augmented Reality App project in XCode.

2. Open your XCode project and drag the ALPS.framework, ALPSKernels.metallib and Realm.framework files from this respository into your project folder inside the Project Navigator pane on the left side of XCode.

3. Click on the project file in the Project Navigator and remove both the ALPS.framework and Realm.framework entries from the "Linked Frameworks and Libraries" section in the "General" tab. Then Add the ALPS.framework and Realm.framework files to the "Embedded Binaries" section. There should now be an entry for the ALPS framework and Realm framework in both of these sections.

4. Navigate to the "Info" tab and add keys for "NSMicrophoneUsageDescription" and "NSCameraUsageDescription". The values of these keys should be strings that tell the user why your app is requesting access to the microphone and camera. An example of one of these could be "Requires microphone acccess for indoor localization".

5. Use the code in the following example as a reference on how to instantiate and obtain location information from ALPS: https://github.com/yodellabs/ALPS-Simple-Example

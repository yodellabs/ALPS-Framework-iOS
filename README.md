<img src="https://github.com/yodellabs/ALPS-Simple-Example/blob/master/logo.png" width="320">

# ALPS-Framework-iOS
The Acoustic Location Processing System (ALPS) framework provides indoor localization services to iOS devices. ALPS uses time-of-flight ranging from ultrasound beacons at known locations to determine the location of the mobile device.

Documentation for the API of the framework can be found here: https://yodellabs.github.io/ALPS-Framework-iOS/

## Adding ALPS to your XCode Project

1. Create a new Augmented Reality App project in XCode.

2. Close XCode and navigate to the root project folder in a terminal.

3. If you do not already have cocoapods installed on your system, run the following command in the terminal:
```
sudo gem install cocoapods
```
4. Create a Podfile and project workspace for your project by running
```
pod init
```
5. Open the Podfile in a text editor and add the following line underneath the "#Pods for" comment
```
pod 'Realm'
```
This specifies that we will be importing the Realm database pod for this project. Save the Podfile and close the editor.

6. Go back to the terminal and run
```
pod install
```
This will download the pods in the podfile and install them. It will also create a workspace for your project. From now on always open the workspace file rather than the project file.

7. Open your XCode project workspace and drag the ALPS.framework and ALPSKernels.metallib files from this respository into your project folder inside the Project Navigator pane on the left side of XCode.

8. Click on the project file in the Project Navigator and remove the ALPS.framework entry from the "Linked Frameworks and Libraries" section in the "General" tab. Then Add the ALPS.framework file to the "Embedded Binaries" section. There should now be an entry for the ALPS framework in both of these sections.

9. Navigate to the "Info" tab and add keys for "NSMicrophoneUsageDescription" and "NSCameraUsageDescription". The values of these keys should be strings that tell the user why your app is requesting access to the microphone and camera. An example of one of these could be "Requires microphone acccess for indoor localization".

10. Use the code in the following example as a reference on how to instantiate and obtain location information from ALPS: https://github.com/yodellabs/ALPS-Simple-Example

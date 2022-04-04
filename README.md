# About NoesisGUIApp
A Visual C++ project template for simple [Noesis GUI](https://www.noesisengine.com/index.php)-based Windows application.

# Prerequisites
- Noesis GUI Native SDK (You can download the free community edition [here](https://www.noesisengine.com/licensing.php))
- Visual Studio 2019 or later (untested in older versions)

# Getting started
- If you have not done so, download and install (unzip) the Noesis GUI SDK. Take note of its directory location.
- Build `NoesisGUI-win-x86_64.sln` solution that comes with the SDK (only NoesisApp library is necessary). 
- Copy NoesisGUIApp distribution zip file to Visual C++ user template directory (`%USERPROFILE%\Documents\Visual Studio 2019\Templates\ProjectTemplates\Visual C++ Project`).
You may also deploy it to system-wide template directory. See [here](https://docs.microsoft.com/en-us/visualstudio/ide/how-to-locate-and-organize-project-and-item-templates?view=vs-2019) for details.
- Restart Visual Studio

# Usage
- Open Visual Studio and create a new project. You should find _NoesisGUI Windows Application_ in the list of project templates.
- Select the project template and proceed with Visual C++ project creation steps.
- In the Solution Explorer find and open `Directory.Build.props` file.
- Set the value of `NoesisSDKDir` property to the directory location of Noesis GUI SDK.
- Build the project. The build should finish with no error.

# Limitations
- The `Directory.Build.props` file is created per project file, and contains the settings for Noesis GUI SDK environment. For a multi-project solution, it's possible to move the file up to the solution directory (as solution item).
- You need to rebuild the project (or solution) if you modify the `Directory.Build.props` file.
- The sample program uses `LocalXAMLProvider` to load XAML files, which means you need to deploy the XAML files along with the built executables. The generated project file comes with a custom build step to automatically copy all XAML files to the build output directory, but for real-world applications it is recommended that you implement your own XAML provider to hide the XAML files.

# Links
- [GitHub repository](https://github.com/satorp/NoesisGUIApp)
- [Noesis GUI](https://www.noesisengine.com/)

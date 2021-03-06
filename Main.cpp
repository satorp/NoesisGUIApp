#include <NsCore/Noesis.h>
#include <NsCore/ReflectionImplementEmpty.h>
#include <NsCore/RegisterComponent.h>
#include <NsApp/LocalXamlProvider.h>
#include <NsApp/LocalFontProvider.h>
#include <NsApp/ApplicationLauncher.h>
#include <NsApp/EntryPoint.h>
#include <NsApp/Application.h>
#include <NsApp/Window.h>
#include <NsGui/IntegrationAPI.h>
#ifdef _DEBUG
#include <windows.h>
#include <strsafe.h>
#endif

namespace $safeprojectname$
{
    class App final : public NoesisApp::Application
    {
        NS_IMPLEMENT_INLINE_REFLECTION_(App, Application, "$safeprojectname$.App")
    };

    class MainWindow final : public NoesisApp::Window
    {
        NS_IMPLEMENT_INLINE_REFLECTION_(MainWindow, Window, "$safeprojectname$.MainWindow")
    };

    class AppLauncher final : public NoesisApp::ApplicationLauncher
    {
    private:
        void RegisterComponents() const override
        {
            Noesis::RegisterComponent<$safeprojectname$::App>();
            Noesis::RegisterComponent<$safeprojectname$::MainWindow>();
        }

        Noesis::Ptr<Noesis::XamlProvider> GetXamlProvider() const override
        {
            return *new NoesisApp::LocalXamlProvider(".");
        }
    };

}

int NsMain(int argc, char** argv)
{
#ifdef _DEBUG
    Noesis::GUI::SetErrorHandler([](const char* file, uint32_t line, const char* message, bool fatal)
        {
            char buf[512];
            ::StringCchPrintfA(buf, _countof(buf), "[%s] %s (%s:%d)\n",
                (fatal ? "FATAL" : "ERROR"),
                message,
                file,
                line);
            ::OutputDebugStringA(buf);
        });
#endif

    // Remove this line to enable Inspector
    Noesis::GUI::DisableInspector();

    $safeprojectname$::AppLauncher launcher;
    launcher.SetArguments(argc, argv);
    launcher.SetApplicationFile("App.xaml");
    return launcher.Run();
}

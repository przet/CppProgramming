#include <windows.h>
#include <Shellapi.h>
//TODO: Include header guards?


class ExecuteFile
{
    public:
    //TODO Having this private resulted in access violotions in
    // derived classes, comeback to this (I would want this to be
    // private
        _In_opt_ HWND hwnd = NULL;
        _In_opt_ LPCTSTR lpOperation = NULL;
        _In_     LPCTSTR lpFile = NULL;
        _In_opt_ LPCTSTR lpParameters = NULL;
        _In_opt_ LPCTSTR lpDirectory = NULL;
        _In_     INT nShowCmd = NULL;
    
    public:
        virtual void SetParamsAndRun(_In_opt_ HWND, _In_opt_ LPCTSTR,
            _In_ LPCTSTR, _In_opt_ LPCTSTR,
            _In_opt_ LPCTSTR, _In_ INT) = 0;
            //TODO pass by reference didn't seems to work in the 
            // function call (i.e when derived class functions used
            // in main)

};

class RunBatch : public ExecuteFile
{
    public:
        void SetParamsAndRun(_In_opt_ HWND, _In_opt_ LPCTSTR,
            _In_ LPCTSTR, _In_opt_ LPCTSTR,
            _In_opt_ LPCTSTR, _In_ INT) override;

};

void RunBatch::SetParamsAndRun(_In_opt_ HWND hwndInput, _In_opt_ LPCTSTR
    lpOperationInput, _In_ LPCTSTR lpFileInput, _In_opt_ LPCTSTR lpParametersInput,
    _In_opt_ LPCTSTR lpDirectoryInput, _In_ INT nShowCmdInput)
{
    hwnd = hwndInput;
    lpOperation = lpOperationInput;
    lpFile = lpFileInput;
    lpParameters = lpParametersInput;
    lpDirectory = lpDirectoryInput;
    nShowCmd = nShowCmdInput;
    ShellExecute(hwnd, lpOperation, lpFile, lpParameters,
        lpDirectory, nShowCmd);
}
class RunProgram : public ExecuteFile
{
    public:
        void SetParamsAndRun(_In_opt_ HWND, _In_opt_ LPCTSTR,
            _In_ LPCTSTR, _In_opt_ LPCTSTR,
            _In_opt_ LPCTSTR, _In_ INT) override;

};

void RunProgram::SetParamsAndRun(_In_opt_ HWND hwndInput, _In_opt_ LPCTSTR
    lpOperationInput, _In_ LPCTSTR lpFileInput, _In_opt_ LPCTSTR lpParametersInput,
    _In_opt_ LPCTSTR lpDirectoryInput, _In_ INT nShowCmdInput)
{
    hwnd = hwndInput;
    lpOperation = lpOperationInput;
    lpFile = lpFileInput;
    lpParameters = lpParametersInput;
    lpDirectory = lpDirectoryInput;
    nShowCmd = nShowCmdInput;
    ShellExecute(hwnd, lpOperation, lpFile, lpParameters,
        lpDirectory, nShowCmd);
}
int main()
{
    RunBatch runBatch;
    RunProgram runProgram;
    //TODO. This feels or seems wrong, to have to instatiate like this...
    runBatch.SetParamsAndRun(NULL, "open", "testBatch.bat",
        NULL, "N:\\Programming\\C++\\CppProgramming\\Projects\\C++_ExeLauncher\\BatchFiles",
        SW_NORMAL);
    
    runBatch.SetParamsAndRun(NULL, "open", "notepad.exe",
        NULL, "C:\\Windows",
        SW_NORMAL);
    

}

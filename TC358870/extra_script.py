Import("env")
platform = env.PioPlatform()

def on_upload(source, target, env):
    upload_tool_path:str = platform.get_package_dir("tool-dfuutil")
    firmware_path = str(source[0])
    env.Execute(f"{upload_tool_path}\\bin\\dfu-suffix.exe -a {firmware_path} -v 0x0483 -p 0xdf11")
    env.Execute(f"{upload_tool_path}\\bin\\dfu-util.exe -R -d 0483:df11 -s 0x08005800 -D {firmware_path}")

env.Replace(UPLOADCMD=on_upload)
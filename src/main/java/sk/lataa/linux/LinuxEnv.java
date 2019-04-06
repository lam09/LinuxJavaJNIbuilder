package sk.lataa.linux;

public class LinuxEnv {
    public native int unsetJVMEnvironmentVariable(String name);

    public native int setJVMEnvironmentVariable(String name, String value, int overwrite);

    public native String getJVMEnvironmentVariable(String name);

}

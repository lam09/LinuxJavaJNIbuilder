package sk.lataa.linux;

public class Test {
    public static void main(String[] args) {
        LinuxEnv linuxEnv = new LinuxEnv();
        linuxEnv.setJVMEnvironmentVariable("lataa", "Hello world", 1);

        String var = linuxEnv.getJVMEnvironmentVariable("lataa");
    }

}

# The python directory
This directory contains the Python versions of the commands.

## Running 

To use these scripts, you need to have Python 3 installed.

If you would like to install these commands as system commands, move them to a the `/usr/local/bin` directory. You will need to run the following command to make them executable:

```bash
chmod +x /usr/local/bin/*.py
```

Then if you want to run them as commands without the `.py` extension, you can create aliases for them in your `.bashrc` file:

```bash
alias <command>="<command>.py"
```

Alternatively you can rename them to remove the `.py` extension.
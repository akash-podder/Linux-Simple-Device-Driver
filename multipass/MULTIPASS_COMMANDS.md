## Multipass Commands
First install `Multipass` in your device. `Multipass` can launch and run `Ubuntu VM` with a single command.

### Installation
https://canonical.com/multipass/install

To install on `MacOS`, run following commands:
```bash
brew install multipass
```

### Multipass Commands
To create an `Ubuntu VM` and other common commands:
```bash
multipass launch --name ramos-instance
multipass list
multipass exec ramos-instance -- lsb_release -a
multipass start ramos-instance
multipass stop ramos-instance
multipass shell ramos-instance
```

### Launch an Instance
Launch an instance (by default you get the current Ubuntu LTS):
```bash
multipass launch --name ramos-instance
```

### Run Commands in Instance
Run commands in that instance, try running bash (logout or `ctrl-d` to quit):
```bash
multipass exec ramos-instance -- lsb_release -a
```

### Access Instance Shell
To access an instance named `ramos-instance`:
```bash
multipass shell ramos-instance
```

If you omit the instance name, you will get a shell for the primary instance (which is automatically `created` if it doesn't exist):
```bash
multipass shell
```

### See Your Instances
```bash
multipass list
```

### Stop and Start Instances
```bash
multipass stop ramos-instance
multipass start ramos-instance
```

### Clean Up What You Don't Need
```bash
multipass delete ramos-instance
multipass purge
```

### Find Alternate Images to Launch
```bash
multipass find
```

### Pass a Cloud-Init Metadata File
Pass a cloud-init metadata file to an instance on launch (See Using cloud-init with Multipass for more details):
```bash
multipass launch --name ramos-instance --cloud-init cloud-config.yaml
```

### Get Help
```bash
multipass help
multipass help <command>
```
## `ssh` into a Multipass Instance

To install on `MacOS`, run following commands:
```bash
sudo vim /etc/ssh/sshd_config
```

Now, go and search `KbdInteractiveAuthentication no`
make it to `yes`

```bash
KbdInteractiveAuthentication yes
```

Then reload the `systemctl` Daemon
```bash
sudo systemctl daemon-reload
```
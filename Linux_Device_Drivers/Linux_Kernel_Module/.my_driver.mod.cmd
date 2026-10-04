savedcmd_my_driver.mod := printf '%s\n'   my_driver.o | awk '!x[$$0]++ { print("./"$$0) }' > my_driver.mod

FROM archlinux:latest

RUN pacman-key --init && pacman-key --populate archlinux
RUN pacman -Syu --noconfirm base base-devel

RUN pacman -S --noconfirm git strace

COPY ./drifblim.c .
RUN gcc -o drifblim drifblim.c && mv ./drifblim /sbin/ && rm drifblim.c

RUN sed -i -e '/NOPASSWD/ s/^# %wheel/%wheel/' /etc/sudoers
RUN useradd -m -G wheel user

USER user

ENTRYPOINT /sbin/drifblim





# 拉取镜像

`docker pull homeassistant/home-assistant`



启动容器

`docker run -d --name="homeassistant" --restart=always --net=host -v /mnt/sda1/local/docker/homeassistant:/config -v /run/dbus:/run/dbus:ro -e TZ=Asia/Shanghai homeassistant/home-assistant:latest`
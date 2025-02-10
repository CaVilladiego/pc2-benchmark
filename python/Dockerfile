From debian:12

RUN apt-get update
RUN apt-get install -y python3

COPY ./pc2-benchmark/python/main.py .

CMD ["time","python3","main.py"]


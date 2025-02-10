From debian:12

RUN apt-get update
RUN apt-get install -y ruby-full

COPY ./pc2-benchmark/ruby/main.rb .

CMD ["time","ruby","main.rb"]


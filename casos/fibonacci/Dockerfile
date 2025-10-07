# ===============================================
# Dockerfile para fibonacci Benchmark TCC
# Node.js, Bun, Deno + ferramentas de benchmark
# ===============================================
FROM ubuntu:24.04

LABEL maintainer="Pedro Gabriel Caires Silva"
ENV DEBIAN_FRONTEND=noninteractive

# =====================
# Atualiza e instala dependências básicas + Python + pip
# =====================
RUN apt-get update && apt-get install -y \
    curl wget unzip ca-certificates gnupg git bash \
    build-essential htop sysstat python3 python3-pip \
    && pip3 install --break-system-packages psutil \
    && rm -rf /var/lib/apt/lists/*

# =====================
# Instala Node.js (última versão estável)
# =====================
RUN curl -fsSL https://deb.nodesource.com/setup_current.x | bash - \
    && apt-get install -y nodejs \
    && node --version && npm --version

# =====================
# Instala Deno
# =====================
RUN curl -fsSL https://deno.land/install.sh | sh \
    && mv /root/.deno/bin/deno /usr/local/bin/deno \
    && deno --version

# =====================
# Instala Bun
# =====================
RUN curl -fsSL https://bun.sh/install | bash \
    && mv /root/.bun/bin/bun /usr/local/bin/bun \
    && bun --version

# =====================
# Instala hyperfine (benchmark de tempo)
# =====================
RUN curl -L https://github.com/sharkdp/hyperfine/releases/download/v1.17.0/hyperfine_1.17.0_arm64.deb -o hyperfine.deb \
    && apt install -y ./hyperfine.deb \
    && rm hyperfine.deb

# =====================
# Instala hey (benchmark HTTP)
# =====================
RUN curl -L https://hey-release.s3.us-east-2.amazonaws.com/hey_linux_arm64 -o /usr/local/bin/hey \
    && chmod +x /usr/local/bin/hey

# =====================
# Define diretório de trabalho
# =====================
WORKDIR /casos/fibonacci

# =====================
# Copia o conteúdo da pasta fibonacci
# =====================
COPY . /casos/fibonacci

# =====================
# Mantém o container aberto para comandos interativos
# =====================
CMD ["bash"]

# Comparação de Runtimes JavaScript: Performance, Eficiência e Adequação de Uso

Este repositório contém os **casos de teste**, **resultados experimentais** e **código-fonte** utilizados no Trabalho de Conclusão de Curso (TCC) *"Comparação de Runtimes JavaScript: Performance, Eficiência e Adequação de Uso"*.

O objetivo é avaliar diferentes runtimes de JavaScript quanto à **performance**, **uso de recursos do sistema** e **adequação de uso em cenários reais**.

---

## Runtimes Avaliados
- **Node.js** – Runtime mais consolidado, baseado em V8.
- **Bun** – Runtime moderno, focado em performance, baseado em JavaScriptCore.
- **Deno** – Criado pelos fundadores do Node, com foco em segurança e suporte nativo a TypeScript/ESM.
- **Fibotime (QuickJS custom)** – Runtime experimental criado especificamente para este trabalho, baseado no QuickJS.

---

## Cenários de Teste

### 1. Processamento de Requisições HTTP
- **Aplicação 1**: Servidor HTTP criado com a biblioteca padrão `http` do JavaScript (mesmo código para todos os runtimes).
- **Aplicação 2**:  
  - **Bun e Deno** → Servidores criados com bibliotecas nativas de cada runtime.  
  - **Node e Fibotime** → Utilizaram o mesmo código da aplicação 1.  

### 2. Execução de Fibonacci Recursivo
- Implementação pura em JavaScript, sem bibliotecas adicionais.
- **Aplicação 1**: mesmo código executado em todos os runtimes.
- O algoritmo foi configurado para ter **carga computacional suficiente** (vários segundos de execução), permitindo análise comparativa.

### 3. Aplicação React
- **Aplicação 1**: Criada com **React + Vite**, garantindo compatibilidade entre Node, Bun e Deno (apenas mudando o gerenciador de pacotes).
- **Observação**: Frameworks nativos de Deno como Fresh e Aleph foram estudados, mas optou-se por manter o código idêntico entre runtimes para isolar a variável "runtime".

---

## Como Executar

### Pré-requisitos
- Node.js ≥ 20
- Bun ≥ 1.0
- Deno ≥ 1.44
- QuickJS (compilado como `fibotime`)

# Apresentção de TEI-HPC

## Projecto _Kaleidoscope_ da _Repsol_

Alunos:

+ Bernardo Marques 18373

+ Gonçalo Amaro 17440

+ Hugo Silva 16570

# Projecto _Kaleidoscope_ da _Repsol_
_Kaleidoscope_ é um projecto de colaboração tecnológico entre a _Emerson_ e a _Repsol_ projectado para trazer tecnologias avançadas de imagem sísmica de sub-superfície para a indústria de petróleo e gás.

# Projecto _Kaleidoscope_ da _Repsol_
Como parte do projecto, a _Emerson_ implementará e implantará soluções avançadas de imagem de sub-superfície com base nas tecnologias centrais da _Repsol_.

# Projecto _Kaleidoscope_ da _Repsol_
Combinando o que há de mais moderno em visualização computacional de ponta e em computação de alto desempenho, as soluções estarão disponíveis para a comunidade de geociências da _Repsol_ e para todas as empresas de petróleo e gás que optem por licenciar as tecnologias, para apoiar os seus processos de transformação digital.

# A máquina onde se processa
A _Repsol_ aliou-se ao centro de super-computação de Barcelona, Espanha, a qual disponibiliza tempo-_CPU_ do seu supercomputador _MareNostrum_.

O MareNostrum_ é uma máquina com capacidade de processamento de 13.7 _petaflops_ e de armazenamento de 14 _petabytes_ e é o maior supercomputador da Península Ibérica.

# A máquina onde se processa
Este divide-se um dois blocos: um de propósito geral e um de tecnologias emergentes.

O bloco principal tem 48 _racks_ com 3456 _nodes_ com um Lenovo ThinkSystem SD530, que é composto por dois Intel Xeon Platinum com 24 _cores_ (48 _threads_) cada, um total de 165888 processadores e uma memória _RAM_ de 390 _terabytes_.

+ item Um é composto por _racks_ de _GPUs_, nomeadamente racks com _NVIDIA_ Volta _GPUs_ e outros com _IMP POWER9_. Este _cluster_ tem uma capacidade computacional de 1.5 _petaflops_.

# A máquina onde se processa
+ item Outro composto por tecnologias da _AMD_, com _CPUs AMD EPYC_ de arquitectura _Rome_ e _CPUs Radeon Instinct MI50_. Este pequeno _cluster_ sozinho tem uma capacidade de 0.52 _petaflops_, equivalente ao supercomputador _Frontier_ na _Oak Ridge National Laboratory_.

+ O ultimo é composto por processadores _ARMv8_ desenhados para alto desempenho, contrariamente aos _ARMv8_ que encontramos nos nossos dispositivos _mobile_ (que são desenhados para o menor custo energético e térmico). Com um poder total de 0.65 _petaflops_.

# O porquê?
Um _survey_ geológico a uma área geográfica, tem um _dataset_ de entre 10 a 20 _terabytes_, uma pequena simulação de fluidos num computador _desktop_ comum, já requer algum tempo de renderização incluindo com paralelismo auxiliado pela _GPU_.

# O porquê?
Logo com um _dataset_ dessa larga escala, necessita de um outro nível de paralelismo e auxilio a algoritmos eficientes.

# Como funciona?
É um sistema de simulação de fluidos altamente paralelizado com recurso a _datasets_ precisos e recentes de dados geológicos. 

# Como funciona?
Este divide a área de cálculo, quer o modelo seja bi ou tri-dimensional em células com percepção e comunicação entre si, onde os fluidos (cujo os mesmo são compostos de partículas) quando sua parte sai dos limites da célula e entra na célula adjacente é comunicado o seu estado e características (movimento, força, etc.).

# Como funciona?
Aqui temos um [video explicativo](https://www.youtube.com/watch?v=Yd4blFeRTEw). Assistam com atenção, os detalhes deste video adecuam-se de certa forma ao metodo usado pela _Repsol_ no seu projecto.

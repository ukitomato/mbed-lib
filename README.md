Mbed IC Library
====

Mbedの各種IC用自作ライブラリ

## Description
- ファンクションジェネレータ AD9833
- 16ch-アナログマルチプレクサ CD74HC4067

## Requirement
- MbedCLI
- gcc-arm-none-eabi
- mbed LPC1768

## Usage
- mbedのCMakeプロジェクト
- 通常のmbedプロジェクトをローカル環境で開発できるようにMbedCLIのexport機能を用いて，mbed LPC1768/GCC_ARM用に変換済み
- CMakeプロジェクトを読み込めるIDE等（CLion）で開発可能
## Install
```bash
$ git clone https://github.com/ukitomato/mbed-lib.git
$ mbed import mbed-lib
```
## Author

[ukitomato](https://github.com/ukitomato)

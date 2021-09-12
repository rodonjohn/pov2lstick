# pov2lstick

You can use the joypad's POV (hat switch) as the L-stick in applications that use DirectInput8.

ex. Touhou

## How to use

Copy dinput.dll in the "bin" folder to the same directory as the executable file (.exe) of the application you want to use.

For 32-bit applications, use the one in the x86 folder; for 64-bit applications, use the one in the x64 folder.

## Attention

* While using this DLL, the L-stick of the joypad will not respond at all.
* I have confirmed that it only works for Touhou, so it may not be available for other applications.

---

# pov2lstick

DirectInput8 を使用しているアプリケーションで、ジョイパッドのハットスイッチ (POV) を左スティックとして操作できるようにするための DLL です。

東方原作など、ハットスイッチを使用できないアプリケーションでハットスイッチが使えるようになります。

## 使い方

bin フォルダの中にある dinput.dll を、使用したいアプリケーションの実行ファイル(.exe)と同じディレクトリにコピーしてください。

32bit アプリケーションの場合は x86 フォルダのものを、64bit アプリケーションの場合は x64 フォルダのものを使用してください。

## 注意

* このDLLを使用している間は、ジョイパッドの左スティックが全く反応しなくなります。
* 東方以外での動作を確認していないので、特殊な使い方をしているようなアプリケーションでは利用できない可能性があります。

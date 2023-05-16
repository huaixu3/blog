# tmux learn

## define
| name    | remark                                  |
|---------|-----------------------------------------|
| session | 一个tmux实例(可包含多个window)          |
| window  | 一个可视化区域（可以显示一个或多个pane) |
| pane    | 一个可视化区域，window的子集            |

## session

| name   | action                                    | remark |
|--------|-------------------------------------------|--------|
| add    | tmux new -s <session-name>                |        |
| ls     | tmux ls                                   |        |
| attach | tmux attach -t <session-name>             |        |
| exit   | tmux detach                               |        |
| kill   | tmux kill-session -t <session-name>       |        |
| rename | tmux rename-session <old-name> <new-name> |        |

## window
Ctrl+b c：创建一个新窗口。
Ctrl+b &：关闭当前窗口。
Ctrl+b n：切换到下一个窗口。
Ctrl+b p：切换到上一个窗口。
Ctrl+b %：水平拆分当前窗格。
Ctrl+b "：垂直拆分当前窗格。
Ctrl+b arrow key：在不同的窗格之间移动光标。
Ctrl+b d：分离当前 session。
Ctrl+b [：进入复制模式。
Ctrl+b ]：粘贴复制的内容。

## pane

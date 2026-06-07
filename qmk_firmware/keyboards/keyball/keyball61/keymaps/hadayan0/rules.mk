# レイヤー状態やモード状態をLED色で確認できるようにする。
RGBLIGHT_ENABLE = yes

# OLEDにレイヤー、スクロール状態、CPIなどの状態情報を表示する。
OLED_ENABLE = yes

# Remap/VIAでキーマップをブラウザから変更できるようにする。
VIA_ENABLE = yes

# Remapで割り当てる音量・ミュートキーをWindowsへ送信する。
EXTRAKEY_ENABLE = yes

# 追加で有効化を検討できるQMK機能。
# 必要な行だけコメントアウトを解除して有効化する。
# hadayan0はファーム容量が厳しいため、有効化後は必ずビルドサイズを確認する。

# キー操作でマウスカーソル移動、クリック、ホイール操作を行う。
# トラックボールとは別に、キーだけでマウス操作したい場合に使う。
#MOUSEKEY_ENABLE = yes

# Nキーロールオーバーを有効化する。
# 多数キーの同時押しを安定して扱いたい場合に使う。
#NKRO_ENABLE = yes

# 起動時のキー操作でEEPROM設定変更やリセットを行う。
# トラブル対応には便利だが、誤操作で設定が変わると原因追跡が難しくなる。
#BOOTMAGIC_ENABLE = yes

# hid_listenなどでファーム内のデバッグログをPCへ出力する。
# 不具合調査には有用だが、ファーム容量を大きく消費する。
#CONSOLE_ENABLE = yes

# QMKのマジックコマンドを有効化する。
# デバッグ切替やNKRO切替などに使えるが、常用では誤操作と容量増に注意する。
#COMMAND_ENABLE = yes

# Shift単押しで括弧、長押しでShiftのようなSpace Cadet系キーを使う。
# 括弧入力を高速化したい場合に検討する。
#SPACE_CADET_ENABLE = yes

# Escと ` / ~ を兼ねるGrave Escape系キーを使う。
# 小型キーボードでキー数を節約したい場合に検討する。
#GRAVE_ESC_ENABLE = yes

# EEPROMリセットなどのMagic keycodeを使う。
# Remap中心の運用では必須ではないが、トラブル対応用キーを置きたい場合に検討する。
#MAGIC_ENABLE = yes

# 音を鳴らすQMK Audio機能を使う。
# Keyball61では通常不要で、ハードウェア構成と容量面の確認が必要。
#AUDIO_ENABLE = yes

# キースイッチ側の単色バックライトを使う。
# KeyballのRGB LED制御とは別機能。
#BACKLIGHT_ENABLE = yes

# PCスリープ中にLEDをブレス点灯させる。
# Keyball61本体側でタイマー競合の注意があるため、基本的には有効化しない。
#SLEEP_LED_ENABLE = yes

# RGB Matrix機能を使う。
# Keyball61ではRGBLIGHT側を使っており、現状は基本的に有効化しない。
#RGB_MATRIX_ENABLE = yes

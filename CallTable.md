| caller function   | called function |
| ----------------- | --------------- |
| main              | initialize_bomb <br> read_line <br> phase_defused <br> bombphase_1 <br> bombphase_2 <br> bombphase_3 <br> bombphase_4 <br> bombphase_5 <br> bombphase_6 |
| initialize_bomb   | sig_handler <br> spider <br> bird <br> eagle |
| read_line         | skip <br> send_msg <br> trigger_bomb_now |
| phase_defused     | send_msg <br> strings_not_equal <br> mqsecretphase |
| bombphase_1       | trigger_bomb_now |
| bombphase_2       | my_strncmp <br> my_strlen <br> trigger_bomb_now |
| bombphase_3       | trigger_bomb_now |
| bombphase_4       | trigger_bomb_now |
| bombphase_5       | trigger_bomb_now |
| bombphase_6       | func_6 <br> trigger_bomb_now |
| sig_handler       ||
| spider            ||
| bird              ||
| eagle             | notifier_603 <br> notifier_936 <br> notifier_871 |
| skip              | blank_line |
| send_msg          | deer |
| trigger_bomb_now  | send_msg |
| strings_not_equal | string_length |
| mqsecretphase     | read_line <br> trigger_bomb_now <br> fun7 <br> phase_defused |
| my_strncmp        ||
| my_strlen         ||
| notifier_603      ||
| notifier_936      ||
| notifier_871      | notifier_60 |
| blank_line        ||
| deer              | notifier_603 <br> notifier_936 <br> notifier_871 |
| string_length     ||
| fun7              | fun7 |
| notifier_60       ||




initially num_input_strings = 0
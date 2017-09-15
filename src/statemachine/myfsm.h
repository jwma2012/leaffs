#ifndef _FSM_h_
#define _FSM_h_

void fsm_init(fsm_t* p_fsm);
void fsm_register(fsm_t* p_fsm,state_table_s* p_state_table,int fsm_id,int cur_fsm_tablesize);
void fsm_begin(fsm_t* p_fsm,int fsm_id);
void fsm_move_state(fsm_t* p_fsm,int state);
void fsm_event_handler(fsm_t* p_fsm,int event);
void fsm_push(fsm_t* p_fsm);
void fsm_pop(fsm_t* p_fsm);

#endif
//#ifndef __REFEREE_H_
//#define __REFEREE_H_
//#include "main.h"
//
//
//
//
///*****************referee data part*****************/
//
//typedef enum
//{
//    RED_HERO        = 1,
//    RED_ENGINEER    = 2,
//    RED_STANDARD_1  = 3,
//    RED_STANDARD_2  = 4,
//    RED_STANDARD_3  = 5,
//    RED_AERIAL      = 6,
//    RED_SENTRY      = 7,
//    BLUE_HERO       = 11,
//    BLUE_ENGINEER   = 12,
//    BLUE_STANDARD_1 = 13,
//    BLUE_STANDARD_2 = 14,
//    BLUE_STANDARD_3 = 15,
//    BLUE_AERIAL     = 16,
//    BLUE_SENTRY     = 17,
//} robot_id_t;
//typedef enum
//{
//    PROGRESS_UNSTART        = 0,
//    PROGRESS_PREPARE        = 1,
//    PROGRESS_SELFCHECK      = 2,
//    PROGRESS_5sCOUNTDOWN    = 3,
//    PROGRESS_BATTLE         = 4,
//    PROGRESS_CALCULATING    = 5,
//} game_progress_t;
//
//
////����״̬���ݣ�0x0001������Ƶ�ʣ�1Hz�����ͷ�Χ�����л����ˡ�
//typedef __packed struct //0001
//{
//    uint8_t game_type : 4;      //0-3bit 1���״�ʦ��,2����,3 ICRA, 4 3v3������ ,5 ������1v1
//    uint8_t game_progress : 4;  //4-7bit ��ǰ�����׶� 0δ��ʼ , 1׼�� 2�Լ� 3 5s����ʱ 4��ս�� 5����������
//    uint16_t stage_remain_time; //��ǰ�׶�ʣ��ʱ�䣬��λ s
//    uint64_t SyncTimeStamp;     //Unix��ȷʱ�� �����ض��յ���Ч�� NTP ��������ʱ����Ч
//} ext_game_state_t;
//
//
////����������ݣ�0x0002������Ƶ�ʣ������������ͣ����ͷ�Χ�����л����ˡ�
//typedef __packed struct //0002
//{
//    uint8_t winner; //0ƽ�� 1�� 2��
//} ext_game_result_t;
//
//
////������Ѫ�����ݣ�0x0003������Ƶ�ʣ�1Hz�����ͷ�Χ�����л����ˡ�
//typedef __packed struct
//{
//    uint16_t red_1_robot_HP;//�� 1 Ӣ�ۻ�����Ѫ����δ�ϳ��Լ�����Ѫ��Ϊ 0
//    uint16_t red_2_robot_HP;//����
//    uint16_t red_3_robot_HP;//����
//    uint16_t red_4_robot_HP;//����
//    uint16_t red_5_robot_HP;//����
//    uint16_t red_7_robot_HP;//�ڱ�
////    uint16_t red_outpost_HP;
//
//    uint16_t red_base_HP;
//    //TODO:����������ǰ��վ
//    uint16_t blue_1_robot_HP;//�� 1 Ӣ�ۻ�����Ѫ����δ�ϳ��Լ�����Ѫ��Ϊ 0
//    uint16_t blue_2_robot_HP;//����
//    uint16_t blue_3_robot_HP;//����
//    uint16_t blue_4_robot_HP;//����
//    uint16_t blue_5_robot_HP;//����
//    uint16_t blue_7_robot_HP;//�ڱ�
////    uint16_t blue_outpost_HP;
//    uint16_t blue_base_HP;
//} ext_game_robot_HP_t;
//
//
////�����¼����� ����Ƶ�ʣ�1Hz ���ڷ��ͣ����ͷ�Χ�����������ˡ�
//typedef __packed struct //0101
//{
//  /*
//   * bit0 ��������վ 1 �Ų�Ѫ��ռ��״̬ 1 Ϊ��ռ�죻
//   *    1 ��������վ 2 �Ų�Ѫ��ռ��״̬ 1 Ϊ��ռ��;
//   *    2 ��������վ 3 �Ų�Ѫ��ռ��״̬ 1 Ϊ��ռ�죻
//   *    3-5 ������������״̬��
//   *    3 Ϊ�����ռ��״̬��1 Ϊռ�죻
//   *    4 ΪС�������ؼ���״̬��1 Ϊ�Ѽ��
//   *    5 Ϊ���������ؼ���״̬��1 Ϊ�Ѽ��
//   *    6 ������ R2/B2 ���θߵ�ռ��״̬ 1 Ϊ��ռ�죻
//   *    7 ������ R3/B3 ���θߵ�ռ��״̬ 1 Ϊ��ռ�죻
//   *    8 ������ R4/B4 ���θߵ�ռ��״̬ 1 Ϊ��ռ�죻
//   *    9 �������ػ���״̬�� 1�� 0��
//   *    10����ǰ��ս״̬��1�� 0��
//   * */
//    uint32_t event_type;
//} ext_event_data_t;
//
//
////TODO:��֪��23��������û�в���������⣬��������Ӧ��Ҫ�İ�
////����վ������ʶ��0x0102������Ƶ�ʣ������������ͣ����ͷ�Χ�����������ˡ�
//typedef __packed struct //0x0102
//{
//    uint8_t supply_projectile_id;
//    uint8_t supply_robot_id;
//    uint8_t supply_projectile_step;
//    uint8_t supply_projectile_num;
//} ext_supply_projectile_action_t;
//
//
//typedef __packed struct //0x0103
//{
//    uint8_t supply_projectile_id;
//    uint8_t supply_robot_id;
//    uint8_t supply_num;
//} ext_supply_projectile_booking_t;
//
////���о�����Ϣ��cmd_id (0x0104)������Ƶ�ʣ����淢�����ͣ����ͷ�Χ�����������ˡ�
//typedef __packed struct
//{
//    uint8_t level;  //����ȼ� 1�� 2�� 3�и�
//    uint8_t foul_robot_id;//���������ID
//} ext_referee_warning_t;
//
////����������״̬��0x0201������Ƶ�ʣ�10Hz
//typedef __packed struct //0x0201
//{
//    uint8_t robot_id;
//    uint8_t robot_level;
//    uint16_t remain_HP;
//    uint16_t max_HP;
//    uint16_t shooter_heat0_cooling_rate;
//    uint16_t shooter_heat0_cooling_limit;
//    uint16_t shooter_heat1_cooling_rate;
//    uint16_t shooter_heat1_cooling_limit;
//    uint8_t mains_power_gimbal_output : 1;
//    uint8_t mains_power_chassis_output : 1;
//    uint8_t mains_power_shooter_output : 1;
//} ext_game_robot_state_t;
//
//typedef __packed struct //0x0202
//{
//    uint16_t chassis_volt;    //���̵�ѹ ����
//    uint16_t chassis_current; //���̵��� ����
//    float chassis_power;      //
//    uint16_t chassis_power_buffer;
//    uint16_t shooter_heat0;
//    uint16_t shooter_heat1;
//} ext_power_heat_data_t;
//
////
//typedef __packed struct //0x0203
//{
//    float x;
//    float y;
//    float z;
//    float yaw;
//} ext_game_robot_pos_t;
//
//typedef __packed struct //0x0204
//{
//    uint8_t power_rune_buff;
//} ext_buff_musk_t;
//
//typedef __packed struct //0x0205
//{
//    uint8_t energy_point;
//    uint8_t attack_time;
//} aerial_robot_energy_t;
//
//
//typedef __packed struct //0x0206
//{
//    uint8_t armor_type : 4; //��Ѫ���仯����Ϊװ���˺�������װ�� ID��������ֵΪ 0-4 �Ŵ�������˵����װ��Ƭ������Ѫ���仯���ͣ��ñ�����ֵΪ 0
//    uint8_t hurt_type : 4;  //Ѫ���仯����
//
//} ext_robot_hurt_t;
//
//typedef __packed struct //0x0207
//{
//    uint8_t bullet_type;
//    uint8_t bullet_freq;
//    float bullet_speed;
//} ext_shoot_data_t;
//
//
////������ RFID ״̬��0x0209������Ƶ�ʣ�1Hz�����ͷ�Χ����һ������
//typedef __packed struct
//{
//  uint32_t rfid_status; //bit 7�����̻����˸�� RFID ״̬��
//} ext_rfid_status_t;
//
//
//typedef __packed struct
//{
//    uint8_t bullet_remaining_num;
//} ext_bullet_remaining_t;
//
//typedef __packed struct //0x0301
//{
//    uint16_t send_ID;
//    uint16_t receiver_ID;
//    uint16_t data_cmd_id;
//    uint16_t data_len;
//    uint8_t *data;
//} ext_student_interactive_data_t;
//
//typedef __packed struct
//{
//    float data1;
//    float data2;
//    float data3;
//    uint8_t data4;
//} custom_data_t;
//
//
//typedef __packed struct
//{
//    uint8_t data[64];
//} ext_up_stream_data_t;
//
//typedef __packed struct
//{
//    uint8_t data[32];
//} ext_download_stream_data_t;
//
////����ϵͳ���ṹ��
//typedef struct {
//  ext_game_robot_HP_t *robotHp;
//  ext_event_data_t *extEventData;//��������Ҫָ��ʱ����Ҫ��
//  ext_power_heat_data_t *powerHeatData;
//  ext_game_robot_pos_t *robotPos;
//  ext_rfid_status_t *rfidStatus;//RFID״̬
//}Referee_t;
//
//
///**************function declaration*************/
//
//extern void init_referee_struct_data(void);
//extern void referee_data_solve(uint8_t *frame);
//
//#endif
//

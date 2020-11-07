void edit_document(const string &filenmae)
{
    open_document_and_display(filenmae);
    while(!done_editing())
    {
        user_command cmd=get_user_input();
        if(cmd.type==open_new_document)
        {
            const string new_name = get_filename_from_user();
            thread t(edit_document, new_name);
            t.detach();
        }
        else
        {
            process_user_input(cmd);
        }
        
    }
}
#include <iostream>
using namespace std;

class slot
{
public:
    int startTime, endTime, min, max;
    bool status;
    slot *next;
    slot(int start, int end, int min, int max)
    {
        startTime = start;
        endTime = end;
        this->min = min;
        this->max = max;
        status = 0;
        next = NULL;
    }
};

slot *head;

void display()
{
    cout << "Sr.No.\tStartTime  EndTime\tMin\tMax\tStatus" << endl;
    int i = 1;
    slot *temp = head;
    while (temp != NULL)
    {
        cout << i << "\t" << temp->startTime << "\t" << temp->endTime << "\t" << temp->max << "\t" << temp->min << "\t";
        if (temp->status == 0)
        {
            cout << "-Free-" << endl;
        }
        else
        {
            cout << "Booked" << endl;
        }
        i++;
        temp = temp->next;
    }
}

void bookAppointment()
{
    int start;
    cout << "Enter the StartTime for booking appointment: ";
    cin >> start;
    slot *temp = head;
    while (temp != NULL)
    {
        if (temp->startTime == start)
        {

            if (temp->status == 0)
            {
                temp->status = 1;
                cout << "Slot Booked Successfully!!!" << endl;
                break;
            }
            else if (temp->status == 1)
            {
                cout << "Sorry, Slot is already Booked!!!" << endl;
                break;
            }
        }
        temp = temp->next;
    }
}

void cancelAppointment()
{
    int start;
    cout << "Enter the StartTime to Cancel appointment: ";
    cin >> start;
    slot *temp = head;
    while (temp != NULL)
    {
        if (temp->startTime == start)
        {

            if (temp->status == 1)
            {
                temp->status = 0;
                cout << "Slot Cancelled Successfully!!!" << endl;
                break;
            }
            else if (temp->status == 0)
            {
                cout << "Sorry, Slot is already Free!!!" << endl;
                break;
            }
        }
        temp = temp->next;
    }
}

void sortAppointments()
{
    slot *temp = head;
    while (temp->next != NULL)
    {
        slot *current = temp->next;
        while (current != NULL)
        {

            if (current->startTime < temp->startTime)
            {
                int val;
                val = current->startTime;
                current->startTime = temp->startTime;
                temp->startTime = val;

                val = current->endTime;
                current->endTime = temp->endTime;
                temp->endTime = val;

                val = current->min;
                current->min = temp->min;
                temp->min = val;

                val = current->max;
                current->max = temp->max;
                temp->max = val;

                bool stat = current->status;
                current->status = temp->status;
                temp->status = stat;
            }
            current = current->next;
        }
        temp = temp->next;
    }
    cout << "Slots Sorted Successfully!!!" << endl;
    display();
}

int main()
{
    int n;
    cout << "Enter the no. of Slots for Today: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, end, min, max;
        cout << "\n\nEnter the Start Time for the slot: ";
        cin >> start;
        cout << "Enter the End Time for the slot: ";
        cin >> end;
        cout << "Enter the Max Duration: ";
        cin >> max;
        cout << "Enter the min Duration: ";
        cin >> min;
        slot *newSlot = new slot(start, end, min, max);
        if (head == NULL)
        {
            head = newSlot;
        }
        else
        {
            slot *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newSlot;
        }
    }
    display();
    char cont = 'y';
    int choice;
    while (cont == 'y')
    {
        cout << "-------------------------------------------------------";
        cout << "\n<----Menu---->" << endl;
        cout << "1.Dispaly Appointment List" << endl;
        cout << "2.Book Appointment" << endl;
        cout << "3.Cancel Appointment" << endl;
        cout << "4.Sort Appointment" << endl;
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            bookAppointment();
            break;
        case 3:
            cancelAppointment();
            break;
        case 4:
            sortAppointments();
            break;
        default:
            cout << "INvalid Choice!!!" << endl;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> cont;
    }
    cout << "Program Ended Successfully!!!" << endl;
    return 0;
}

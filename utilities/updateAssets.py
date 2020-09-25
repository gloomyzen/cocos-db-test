from googleapiclient.http import MediaIoBaseDownload
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request
import io
import os
import pickle
import sys

SCOPES = ['https://www.googleapis.com/auth/drive.readonly']


def main():
    creds = None
    if os.path.exists('token.pickle'):
        with open('token.pickle', 'rb') as token:
            creds = pickle.load(token)
    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())
        else:
            flow = InstalledAppFlow.from_client_secrets_file('credentials.json', SCOPES)
            creds = flow.run_local_server(port=1337)
        with open('token.pickle', 'wb') as token:
            pickle.dump(creds, token)
    service = build('drive', 'v3', credentials=creds)
    print(service)

    # folder_name = ''
    # folder_id = ''
    # location = ''
    # if len(sys.argv) > 2:
    #     location = unicode(sys.argv[2], 'utf-8')
    #     if location[-1] != '/':
    #         location += '/'
    #
    # folder = service.files().list(
    #     q="name contains '{}' and mimeType='application/vnd.google-apps.folder'".format(unicode(sys.argv[1])),
    #     fields='files(id, name, parents)').execute()
    #
    # total = len(folder['files'])
    # if total != 1:
    #     print('{} folders found'.format(total))
    #     if total == 0:
    #         sys.exit(1)
    #     prompt = 'Please select the folder you want to download:\n\n'
    #     for i in range(total):
    #         prompt += u'[{}]: {}\n'.format(i, get_full_path(service, folder['files'][i]))
    #     print prompt
    #     choice = int(raw_input('Your choice: '))
    #     if 0 <= choice and choice < total:
    #         folder_id = folder['files'][choice]['id']
    #         folder_name = folder['files'][choice]['name']
    #     else:
    #         sys.exit(1)
    # else:
    #     folder_id = folder['files'][0]['id']
    #     folder_name = folder['files'][0]['name']
    #
    # print('{} {}'.format(folder_id, folder_name))
    # download_folder(service, folder_id, location, folder_name)


if __name__ == '__main__':
    main()

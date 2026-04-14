## Assignment 3

>

    Name : Ravish Ranjan
    Course : MCA
    Semester : 2nd semester

### Task 1: Finding the Full Email Header

Before analysis can begin, locate the full email header in your email client (Gmail/Outlook). The method differs depending on the platform.

#### Gmail

1. Open Gmail in a web browser and open any email (use a test/sample email provided by your instructor).
2. Click the three dots (More options) in the top-right corner of the email.
3. Select "Show original" from the menu. This will open a new window displaying the full raw email headers.
4. Copy the entire header text from the box shown on that page.

```
Received: from SA3PR19MB7370.namprd19.prod.outlook.com (::1) by
 MN0PR19MB6312.namprd19.prod.outlook.com with HTTPS; Tue, 19 Sep 2023 18:36:46
 +0000
Received: from BN0PR03CA0023.namprd03.prod.outlook.com (2603:10b6:408:e6::28)
 by SA3PR19MB7370.namprd19.prod.outlook.com (2603:10b6:806:317::17) with
 Microsoft SMTP Server (version=TLS1_2,
 cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384) id 15.20.6792.27; Tue, 19 Sep
 2023 18:36:45 +0000
Received: from BN8NAM11FT066.eop-nam11.prod.protection.outlook.com
 (2603:10b6:408:e6:cafe::23) by BN0PR03CA0023.outlook.office365.com
 (2603:10b6:408:e6::28) with Microsoft SMTP Server (version=TLS1_2,
 cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384) id 15.20.6792.28 via Frontend
 Transport; Tue, 19 Sep 2023 18:36:45 +0000
Authentication-Results: spf=temperror (sender IP is 137.184.34.4)
 smtp.mailfrom=ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06; dkim=none (message not
 signed) header.d=none;dmarc=temperror action=none
 header.from=atendimento.com.br;compauth=fail reason=001
Received-SPF: TempError (protection.outlook.com: error in processing during
 lookup of ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06: DNS Timeout)
Received: from ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06 (137.184.34.4) by
 BN8NAM11FT066.mail.protection.outlook.com (10.13.177.138) with Microsoft SMTP
 Server (version=TLS1_2, cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384) id
 15.20.6813.19 via Frontend Transport; Tue, 19 Sep 2023 18:36:44 +0000
X-IncomingTopHeaderMarker:
 OriginalChecksum:3B61F64750F88C5569DF38A496B2374685F23D8BC662A6A19B6823B2F6745D54;UpperCasedChecksum:62071BC7A7CF5B0844A7B406B0E9EFCDAA2CB94988E687CF8C56555AD4B52D30;SizeAsReceived:544;Count:9
Received: by ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06 (Postfix, from userid 0)
	id 39DEA3F725; Tue, 19 Sep 2023 18:35:49 +0000 (UTC)
Content-type: text/html; charset=UTF-8
Content-Transfer-Encoding: base64
Subject: CLIENTE PRIME - BRADESCO LIVELO: Seu cartão tem 92.990 pontos LIVELO expirando hoje!
From: BANCO DO BRADESCO LIVELO<banco.bradesco@atendimento.com.br>
To: phishing@pot
Message-Id: <20230919183549.39DEA3F725@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06>
Date: Tue, 19 Sep 2023 18:35:49 +0000 (UTC)
X-IncomingHeaderCount: 9
Return-Path: root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06
X-MS-Exchange-Organization-ExpirationStartTime: 19 Sep 2023 18:36:44.2236
 (UTC)
X-MS-Exchange-Organization-ExpirationStartTimeReason: OriginalSubmit
X-MS-Exchange-Organization-ExpirationInterval: 1:00:00:00.0000000
X-MS-Exchange-Organization-ExpirationIntervalReason: OriginalSubmit
X-MS-Exchange-Organization-Network-Message-Id:
 b9106deb-bd54-4815-e5c9-08dbb93f5fab
X-EOPAttributedMessage: 0
X-EOPTenantAttributedMessage: 84df9e7f-e9f6-40af-b435-aaaaaaaaaaaa:0
X-MS-Exchange-Organization-MessageDirectionality: Incoming
X-MS-PublicTrafficType: Email
X-MS-TrafficTypeDiagnostic:
 BN8NAM11FT066:EE_|SA3PR19MB7370:EE_|MN0PR19MB6312:EE_
X-MS-Exchange-Organization-AuthSource:
 BN8NAM11FT066.eop-nam11.prod.protection.outlook.com
X-MS-Exchange-Organization-AuthAs: Anonymous
X-MS-UserLastLogonTime: 9/19/2023 6:25:15 PM
X-MS-Office365-Filtering-Correlation-Id: b9106deb-bd54-4815-e5c9-08dbb93f5fab
X-MS-Exchange-EOPDirect: true
X-Sender-IP: 137.184.34.4
X-SID-PRA: BANCO.BRADESCO@ATENDIMENTO.COM.BR
X-SID-Result: NONE
X-MS-Exchange-Organization-PCL: 2
X-MS-Exchange-Organization-SCL: 5
X-Microsoft-Antispam: BCL:9;
X-MS-Exchange-CrossTenant-OriginalArrivalTime: 19 Sep 2023 18:36:44.1298
 (UTC)
X-MS-Exchange-CrossTenant-Network-Message-Id: b9106deb-bd54-4815-e5c9-08dbb93f5fab
X-MS-Exchange-CrossTenant-Id: 84df9e7f-e9f6-40af-b435-aaaaaaaaaaaa
X-MS-Exchange-CrossTenant-AuthSource:
 BN8NAM11FT066.eop-nam11.prod.protection.outlook.com
X-MS-Exchange-CrossTenant-AuthAs: Anonymous
X-MS-Exchange-CrossTenant-FromEntityHeader: Internet
X-MS-Exchange-CrossTenant-RMS-PersistedConsumerOrg:
 00000000-0000-0000-0000-000000000000
X-MS-Exchange-Transport-CrossTenantHeadersStamped: SA3PR19MB7370
X-MS-Exchange-Transport-EndToEndLatency: 00:00:02.6179349
X-MS-Exchange-Processed-By-BccFoldering: 15.20.6792.025
X-Microsoft-Antispam-Mailbox-Delivery:
	wl:1;pcwl:1;ucf:0;jmr:0;ex:0;psp:0;auth:0;dest:I;OFR:TrustedSenderList;ENG:(5062000305)(920221119095)(90000117)(920221120095)(91040095)(9050020)(9075021)(9100341)(944500132)(2008001134)(4810010)(4910033)(9610028)(9560006)(10180021)(9439006)(9310011)(9220031)(120001);
X-Message-Info:
	qZelhIiYnPlgo3oeAkqKQrb/Je8fpvpPmRGjYwLej8PYXc5p/l16IG5I8gDUPoij+JWSvja0BAMLtkgrOcbx5zEN7V98T2UZUZs4k8BX/DcDfI7QJ0t2aouiqx4ENvkR1M3sDKP/XN09+50x9Rxi6onUtDV4eqq36VUi2qAa0zCzkJwjdl3Y9DzNE1OkaWjrHAizeUyMZ/UtK/Pz9zhA2A==
X-Message-Delivery: Vj0xLjE7dXM9MDtsPTA7YT0wO0Q9MTtHRD0yO1NDTD0tMQ==
X-Microsoft-Antispam-Message-Info:
	=?utf-8?B?QTlXRFVaTVRhbmFzVTRkbVBTSFRSUURrQTRyaDhzZVczY2RROWF3bVVDTWdk?=
 =?utf-8?B?bVU0VHJ2UU9wWUFLbXlFRWVUcmx1Z244ajk4M0JMRVYzZW9WVkE3NVZpK0dp?=
 =?utf-8?B?STVZSUFyRzdvQWNJeXEyNlNrZnBxcG9rZk5zQTAvMzBPbExJWWg2SFhEQWVv?=
 =?utf-8?B?RE1CeEhuMzB6Z0hkUWdoNDRWN0U0Y1JHcjlxOGRMUTRVOFBHR1RRTFlnNTBT?=
 =?utf-8?B?Qzc5S2xhOHJiZE5KTWFYeGlESnJyY0oxei9CZVFRQitEaXQrT0k3OFpnYWRJ?=
 =?utf-8?B?ckQyOGwxMEdqZlM1Umk2Tkd6aHhNU3JCOWJIUmJlT0lwN2MyRGtjbUo0SFpH?=
 =?utf-8?B?UVVxUng1VW5rVkd0K3JySSt5VkVkODNhR25RbDBwUXQrYk81ZGlQOEhsV25y?=
 =?utf-8?B?R2tkNC9nekd3V1NaN3dSMDB0M2s1eW4xbzRwelZiL0trY1BVVFBHSFZrK2FC?=
 =?utf-8?B?cUpISXFkRG1TTVhkRUhmcWtiSGp4amFWdWZTb3pPQU5lRkZyL1dJWWVKQnF4?=
 =?utf-8?B?T0Exb3JldEFyN01ScHFZZUhsMnpRam9aMFFLNGFVVUhsTEhYOFNDdUNVd1ZY?=
 =?utf-8?B?UEFZQVJaN2VoSWdwdnJFY3FIQjN2OGlIOThpZFRNTk1hQW5rUHljbVV3VDJP?=
 =?utf-8?B?YSs0VFd2dExMcnhHZ2l1UUhLUm5ESS9DTnBYazg3UE83b2o4ZHQzS05ROXpk?=
 =?utf-8?B?cWhrUGd1eFl4QlhTMlQwTkp3RFZqZVRpbUpKZnpoZGlRUGQxaDJVTFlSNmZa?=
 =?utf-8?B?NUp1RDRIYmRIT0h3RHJRK1ZBMkRMczBZbkVvd1MrVERwSytRMTlQWlhoY0R6?=
 =?utf-8?B?V2JqRFdLQzZLb0NseTJCRHhmRlppV0FDclQ0cjRaQ1NFeGZWOVpOQ2t0OStn?=
 =?utf-8?B?M3FUZFVmbSt5Vk1kenFhQlVLb0YwTlhFOHMzN3hyS2NMSVI1eHhvempuOFZG?=
 =?utf-8?B?ZlZ6L3lrQU80YTVDMVI3Ym9NNFdrempqdFVOUmRjMWxxakFNdWlXdFAxeXhi?=
 =?utf-8?B?dEVHYzFZNm9jVmdKNTZmQ04rRTdqM0RqQ0w4NWZoTG8wVWlzeTVJNERmc2hO?=
 =?utf-8?B?Qk1yYjRjRzBxeGx1R3JtNTRHbmJCS3oyK2gydGpqeE8xVDZWeHRXd0V4NzM0?=
 =?utf-8?B?aFVZYVRlaHFDSVZkOWVzQ01SaDZFSUIraDN5QkVNcU1pYmdlVm11bk5lVHow?=
 =?utf-8?B?T1RWclBsVWVNR1pQalAySnUwZTNWQmh2VzRzVW1LSDhZcCtqTFYrUUI2M1ZZ?=
 =?utf-8?B?TWRabXhnVHc2MWdXSUh1VWVCcjV3MloxeTZnTUgvOHhYL0ZtMm9TWW8vZ3BE?=
 =?utf-8?B?NS9qKzB3aHJkdEFsZVJMNEFLcUdoZUpQZG1KSmtjbXZyWXk4M1R6czlwWExH?=
 =?utf-8?B?QzY3ZCtVazMzWkhzTFNZcVRUWUZremJQUG1yNjk2Y1gzMzdJdlAvTDBCQjcw?=
 =?utf-8?B?TnhETXozUzJYa2F6cUxEZFRFUnlXTzhiMDNiRkk2WlRFaGF6K0o1Z0d2K0N4?=
 =?utf-8?B?clFYbGpiVUdNSG9hZHRXME85cm1lTUxKMnpUM2RncFVXTzc1UHl1ZFJaY0VL?=
 =?utf-8?B?Tm5TNTVLYjN2bjBURlc4WkhBaFFENTV2cEVmdlFrYkdsS205bGlSSi92LzN2?=
 =?utf-8?B?TDRIKzR3UHIySHduV25NRVpMYXc0WkI3bnJKU3NhN2FZZlFXc3RJOTBMclVi?=
 =?utf-8?B?K1kyM21vL3pYeVR4aXNFUnpNYlhvZ3lzVXF3K1FMU1R6ZmRHWFlHN1RnVFZ2?=
 =?utf-8?B?N0hlaEdwbW8veVZWTmF4dlB0QklaazN4VTd0OVZkWU1vbW4wY1dlVktTYTVo?=
 =?utf-8?B?VzQwaG03NE5SZTNTbk81ajJHNVoyRlRQNGhOZVV6aXZsMTMyUjExaHpqY1Na?=
 =?utf-8?B?TVR3SERhL21INkZNZk9ZUDNCYTV4eHJ0Q0VETGRXUk1jRVhieFZpUHlKYzdX?=
 =?utf-8?B?OWVZUFVPb29iVmtyelJIWmlFckdCM3RlYUtES0tEZDJqM2I1S2tyU0hMYStX?=
 =?utf-8?B?YVlTcURVZndUbTBRNDA1eUg0V0FTQ3RqcUxZVW12cXMyTFVuYXBBNEhCajh6?=
 =?utf-8?B?WkVCNHExeVByUE5vVWFQWkhKN2grYmdZcTY3K3VWaHo3Smxjc24vOGZwNzUw?=
 =?utf-8?B?Y1FVQTZEdEdXR0RmYnJsTUtzY1YxaU9QQUdnemlud2tMaU9nOUx3dFRicW5x?=
 =?utf-8?B?TmlzY3V4NFJnSURIUHBlZjVKY25UTnl4ak1GUS8zaHR5bWxZZENWNGJvNlhG?=
 =?utf-8?B?c21xRzlreGJ3ZWlwa1A3VHlRY09DSHFrRHdSbVR3RmVrcXVXSWJseTg4d1NW?=
 =?utf-8?B?V3k3dWNmT1VzT1ZQN2Z0MjV0L2xYNi9VUFo3WEw1OWwycC85MkxER3R2d2hF?=
 =?utf-8?B?M2VGKzlQamdTYzNKeGgzN2R6TGtjWEN5QU5CV2cxUGJrL1JZRUNXZFZJY0xB?=
 =?utf-8?B?WVI3NUVDSWoxNnk1YS9pUnMybDRJSEdOQm5XZXNzam5FWWozbEhqRnhCTS9h?=
 =?utf-8?B?bVlXa0NzNlBrQVc3UzJSd09TaWcxZ0Nxc0tSOHJIeUEvTFI1cWpkZkNHN3Js?=
 =?utf-8?B?SGQycktlS3dOblZmaUJmN2UvRjZBZ2tzanhiVlBXRDZNb0N5MkhLcFhHb3RP?=
 =?utf-8?B?MitZbWNWd1R4NVNMcEVtYkJVd0xoMVpXZFdLZzZLNDBiZnJyZUkxN09tLzJJ?=
 =?utf-8?B?NVlzUXZhak9RaDRMeHBqVTNaenpLRGw5NHpEYzhXeVBLTXpibVRza2ExNFJm?=
 =?utf-8?B?eXovMjBDenRkcHROdWJuK0NNdVVlZXpxQy9DbTBOWTE0WnoxaGNaaFdOOVhU?=
 =?utf-8?B?NkFsVmN3YmMzZE5vRWgwN0JtOWMyOUJJbWlWczA3NEdYUWhLUzg5eUY5d0N3?=
 =?utf-8?B?aDZBMm4zS1A1cWdoUUIrNUJYelhXWVFqSFN1SExiYmYyQXlrcjZLVWdnamtF?=
 =?utf-8?B?U2xnVDhpbVlkenZGKyszVllDWmdWYWoxdXloS3NYdXlsYlZGcTZHY0RqdzlM?=
 =?utf-8?B?WUM1Um9xcnNFWFFDSHdTcVhEQ0hLZkRzUGVCNHRlSnNFY1BJVlVETmlReFdP?=
 =?utf-8?B?cDVWWFE5OHdKZ1d6Yy9aTUQvQmkvVC9mV3k5UGN4VERyay9EUDVHMlJHNjBS?=
 =?utf-8?B?SnJlNjdCdG5zQUtwQWYrRGhrUVQwNDFoZERIQ285WDUvNDBLVUNCSTYwSFRi?=
 =?utf-8?B?bzNTMjUybzN0TWx6RzNiZVBxRFl0aTRMY3NqdzZGaDcwaDdVczBtd21hbGpK?=
 =?utf-8?B?N3dUOWh5eGtveTNET1Y2V2VncEdRckF4bXU0OFF2K0V3bmk4NWpoMTMvNnRv?=
 =?utf-8?B?QmZ2TkZJZThMS1BKU1dGTU9vZnJEWVI5dzUwRFJDbmhCL2pBSmJYM0lGNW9V?=
 =?utf-8?B?NDV4UGJCQ0tnTG9iYzdrb3ZBVjlzU09LVUlxS3dKaGJiRVlxMXEwT3RBKzJy?=
 =?utf-8?B?TlJJbFZvTm9mbGlFTFVncVUwZHRMT3ZIZDFNcmhSaUx5a0IyN3pYMjU0WWYz?=
 =?utf-8?B?WFp2amorZ2JLVTd1UUVSb1R4bVg0czI2TUpyRE5HREQzQ0FrUldqK1BiUlJs?=
 =?utf-8?B?Y1hqT21UV2dJVmd5ZG9xVDk3U1BUZ0VvckVxM2tyS1BmRTRBPT0=?=
MIME-Version: 1.0
```

5. Paste a screenshot of the Gmail menu and the raw header window.
   ![alt text](image.png)
   ![alt text](image-1.png)

---

### Task 2: Analyse the email in the EML Analyser

1. Load the provided .eml into an EML Analyser.
2. Record the top-level metadata:

| Field         | Value                                                                                |
| ------------- | ------------------------------------------------------------------------------------ |
| Subject       | CLIENTE PRIME - BRADESCO LIVELO: Seu cartão tem 92.990 pontos LIVELO expirando hoje! |
| From          | banco.bradesco@atendimento.com.br                                                    |
| To            | phishing@pot                                                                         |
| Date          | 2023-09-19T18:35:49Z                                                                 |
| Message-ID    | <20230919183549.39DEA3F725@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06>                    |
| Return-Path   | root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06                                           |
| MIME type     | mime-version 1.0 <br> content-type text/html; charset="UTF-8"                        |
| Body encoding | base64                                                                               |

3. List every MIME part, attachment, embedded object or referenced resource.

```
MIME part : text/html; charset="UTF-8"
attachments : None
embedded object : google font stylesheet,images
referenced source : html link tag
    <link href="https://fonts.googleapis.com/css2?family=Signika:wght@300;500;700&amp;display=swap" rel="stylesheet">

    header.png
    icone-superior.png
    icone-rodape.png
```

![alt text](image-2.png) 4. Extract all URLs, domains, email addresses and any observable filenames
URLs

```
https://blog1seguimentmydomaine2bra.me/
```

Domains

```
namprd19.prod.outlook.com
namprd03.prod.outlook.com
protection.outlook.com
outlook.office365.com
atendimento.com.br
```

Emails

```
banco.bradesco@atendimento.com.br
root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06
phishing@pot
```

Filenames

```
header.png
icone-superior.png
icone-rodape.png
```

#### Submit:

5. Screenshot of email header analysis result in a tool
   ![alt text](image-3.png)
6. Results of Steps 2, 3 and 4.

---

### Task 3: Header analysis with MX Toolbox

Paste the raw header into the MX toolbox Email header analyser and submit the following:

- Make a table and record the following:
  [Analysis url](https://mxtoolbox.com/Public/Tools/EmailHeaders.aspx?huid=37119854-90bd-4bbd-a6b6-c42d36cb5416)

| Field                      | Record                                                             |
| -------------------------- | ------------------------------------------------------------------ |
| Displayed from the address | BANCO DO BRADESCO LIVELO <banco.bradesco@atendimento.com.br>       |
| Return-path                | root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06                         |
| Message-ID                 | <20230919183549.39DEA3F725@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06>  |
| Sender/originating IP      | 137.184.34.4                                                       |
| Received mail servers      | ubuntu-s-1vcpu -> Outlook Protection -> Office365 internal servers |
| SPF result                 | temperror                                                          |
| DKIM result                | none                                                               |
| DMARC result               | temperror (no DMARC record)                                        |

1. Is there any mismatch between the displayed sender identity and the actual sender?

```
Yes
    displayed name : BANCO DO BRADESCO LIVELO <banco.bradesco@atendimento.com.br>
    actual sender : root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06 (random ubuntu vps)
```

2. State whether the relay path is consistent with the claimed sender brand.

```
Not consistent
    the first hop is not a bank mail server but is a generic digital ocean vps,so we can conclude that it is not a legitimate email from bank
```

3. From the MX Toolbox results in Task 3, note whether the SPF, DKIM, and DMARC checks passed or failed.

```
None passes properly
    SPF : temperror
    DKIM : none
    DMARC : temperror
```

4. Interpret the SPF result and explain what a temperror means operationally.

```
SPF result (from header) : spf=temperror (DNS Timeout)
    spf checkup failed due to dns lookup failure so the reciever couldn't verify sender authorization

    this could be because of
        Misconfigured domain
        Non-existent domain
        Intentional evasion

```

5. Explain the significance of dkim=none for a bank-branded message.

```
dkmi=none means following things
    there is no cryptographic signature
    there is no verification of domain authenticity
    message integrity is not checked

these are necessary requirements for a banking mail
```

6. Based on your findings, explain below what these results tell you about the legitimacy of the email.

```
the mail is classified as non-legitimate for following reasons
    fake branding
    return path mismatch
    origin from a vps
    SPF failed
    DKIM is missing
    DMARC is missing
    microsoft has marked compauth=fail and SCL=5
```

---

### Task 4: Tracing the Originating IP Address and analysing its reputation

Once you have the originating IP address from the email header, you can investigate further to determine where the email actually originated.

1. Note the x-originating-ip address from your MX Toolbox analysis.

```
the email was not sent from a web ui/ by a user so there is no x-originating-ip, in this case the x-sender-ip can be concidered as one
which is : 137.184.34.4
```

2. Use the originating IP in VirusTotal, AbusePDB, and/or Cisco Talos

[analysis website](https://www.virustotal.com/gui/ip-address/137.184.34.4)
![alt text](image-4.png) 3. Record:

| Field                | Result                                  |
| -------------------- | --------------------------------------- |
| Detection counts     | 0                                       |
| Reputation labels    | 1:not reccomended, 56:clean, 37:unrated |
| ASN/hosting provider | AS14061 - DigitalOcean, LLC             |
| Any abuse history    | Yes, 10 reports                         |

4. State whether the IP ownership is compatible with a legitimate Bradesco/Livelo campaign.

```
No : the ip ownership is not compatible with a legitimate Bradesco/Livelo campaign
    This is because of the results found in ip analysis
        ip address : 137.184.34.4
        Type : vps instance
        ASN: DigitalOcean AS14061
```

5. Paste a screenshot of the IP lookup results below and submit

    ![alt text](image-6.png)
    ![alt text](image-5.png)
    ![alt text](image-7.png)

---

### Task 5 - Domain ownership and URL/Domain analysis

1. Run WHOIS for:
    - atendimento.com.br
    - blog1seguimentmydomaine2bra.me
2. Record:

`atendimento.com.br`

| Field                     | Result                                                                             |
| ------------------------- | ---------------------------------------------------------------------------------- |
| Registrar                 | Under brazilian internet system Centralized (Registro.br only)                     |
| Creation date             | 20-Sep-2018                                                                        |
| Expiry date               | 20-Sep-2027                                                                        |
| Available ownership clues | domain is generic, not brand-owned; no explicit organizational attribution visible |

---

`blog1seguimentmydomaine2bra.me`

**_This domain is not registered_**

| Field                     | Result |
| ------------------------- | ------ |
| Registrar                 | NA     |
| Creation date             | NA     |
| Expiry date               | NA     |
| Available ownership clues | NA     |

3. Submit the extracted URL to urlscan.io and/or VirusTotal URL analysis. Record whether
   the URL:

`atendimento.com.br`

| Field                                        | Result                           |
| -------------------------------------------- | -------------------------------- |
| Redirects                                    | No significant redirect observed |
| Resolves                                     | Yes                              |
| Is already known as malicious or suspicious  | No detection on virus total      |
| The landing domain matches the claimed brand | NA : no specific brancd claim    |

`blog1seguimentmydomaine2bra.me`

| Field                                        | Result |
| -------------------------------------------- | ------ |
| Redirects                                    | NA     |
| Resolves                                     | NA     |
| Is already known as malicious or suspicious  | NA     |
| The landing domain matches the claimed brand | NA     |

---

### Final Questions:

1. Why is a From vs Return-Path mismatch important in phishing analysis?

```
The From address is what the user sees, while the Return-Path indicates the actual sending source used for bounce handling. A mismatch between these fields tells sender spoofing, where the visible identity is forged to appear trustworthy while the actual infrastructure is unrelated.

This is a key phishing indicator because legitimate organizations typically align these fields or use controlled domains. A mismatch implies the attacker is impersonating a trusted identity while sending from unauthorized infrastructure.
```

2. What does dkim=none suggest in the context of this sample?

```
The result dkim=none indicates that the email was not cryptographically signed using DKIM which tells us that there is no verification of domain authenticity or message integrity.
```

3. How should an analyst treat SPF/ DMARC temperror compared with explicit fail or pass results?

```
A temperror indicates a temporary failure in performing the authentication check, usually due to DNS lookup issues.
It does not confirm legitimacy like a pass, nor does it definitively indicate spoofing like a fail.

However, from a security perspective, temperror should be treated as suspicious or untrusted, especially when combined with other anomalies. Analysts should not assume legitimacy and should rely on additional evidence such as header inconsistencies and infrastructure analysis.
```

4. Which observations in this sample are strongest for enterprise blocking and threat-hunting?

```
The strongest indicators include:

- email's from vs return-path mismatch
- DKIM = none tells lack of authentication
- SPF/DMARC temperror tells authentication failure to validate
- Originating IP from generic VPS/cloud infrastructure
- Suspicious or non-corporate mail server hostname
- Email authentication result showing compauth=fail
- Spam confidence indicators

These signals are reliable for both automated blocking and threat-hunting, as they indicate unauthenticated and potentially malicious email infrastructure.
```

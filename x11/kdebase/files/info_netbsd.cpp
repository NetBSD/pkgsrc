/*
 * $NetBSD: info_netbsd.cpp,v 1.2 1999/07/19 21:05:16 tron Exp $
 *
 * info_netbsd.cpp is part of the KDE program kcminfo.  This displays
 * various information about the NetBSD system it's running on.
 *
 * This code is derived from code written by
 *	Jaromir Dolecek <dolecek@ics.muni.cz>
 *
 * CPU info code has been imported from abs's processor.cpp implementation
 * for KDE 1.0 with only minor formatting changes
 */

#define INFO_CPU_AVAILABLE
#define INFO_IRQ_AVAILABLE
/* #define INFO_DMA_AVAILABLE */ /* not really available */
#define INFO_PCI_AVAILABLE
#define INFO_IOPORTS_AVAILABLE
#define INFO_SOUND_AVAILABLE
#define INFO_DEVICES_AVAILABLE
#define INFO_SCSI_AVAILABLE
#define INFO_PARTITIONS_AVAILABLE
#define INFO_XSERVER_AVAILABLE


/*
 * all following functions should return TRUE, when the Information 
 * was filled into the lBox-Widget. Returning FALSE indicates that
 * information was not available.
 */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <stdio.h>	/* for NULL */
#include <stdlib.h>	/* for malloc(3) */

#include <qfile.h>
#include <qfontmetrics.h>

typedef struct
  {
  int	string;
  int	name;
  char	*title;
  } hw_info_mib_list_t;

bool GetInfo_CPU(KTabListBox *lBox)
{
  static hw_info_mib_list_t hw_info_mib_list[]= {
	{ 1, HW_MODEL,		"Model" },
	{ 1, HW_MACHINE,	"Machine" },
	{ 1, HW_MACHINE_ARCH,	"Architecture" },
	{ 0, HW_NCPU,		"Number of CPUs" },
	{ 0, HW_PAGESIZE,	"Pagesize" },
	{ 0,0,0 }
	};
  hw_info_mib_list_t *hw_info_mib;
  
  int mib[2], num;
  char *buf, numbuf[sizeof(num)*3+1];
  size_t len;
  QString value;

  lBox->setNumCols(2);
  lBox->setSeparator('');
  lBox->setColumn(0, i18n("Information"), 150);
  lBox->setColumn(1, i18n("Value"));

  for ( hw_info_mib = hw_info_mib_list ;  hw_info_mib->title ; ++hw_info_mib )
  {
	mib[0] = CTL_HW;
	mib[1] = hw_info_mib->name;
	if ( hw_info_mib->string ) {
		sysctl(mib,2,NULL,&len,NULL,0);
		if ( (buf = (char*)malloc(len)) ) {
			sysctl(mib,2,buf,&len,NULL,0);
			value = QString(buf);
			free(buf);
		}
		else {
			value = QString("Unknown");
		}
	}
	else {
		len = sizeof(num);
		sysctl(mib,2,&num,&len,NULL,0);
		value.sprintf("%d", num);
	}
	lBox->insertItem(QString(hw_info_mib->title) + QString("") +
		value);
   }

   return true;
}

// this is used to find out which devices are currently
// on system
static bool GetDmesgInfo(KTabListBox *lBox, const char *filter,
	void func(KTabListBox *, QString s, void **, bool))
{
        QFile *dmesg = new QFile("/var/run/dmesg.boot");
	bool usepipe=false;
	FILE *pipe=NULL;
	QTextStream *t;
	bool seencpu=false;
	void *opaque=NULL;
	QString s;
	bool found=false;

	if (dmesg->exists() && dmesg->open(IO_ReadOnly)) {
		t = new QTextStream(dmesg);
	}
	else {
		delete dmesg;
		pipe = popen("/sbin/dmesg", "r");
		if (!pipe) return false;
		usepipe = true;
		t = new QTextStream(pipe, IO_ReadOnly);
	}

	lBox->setAutoUpdate(false);
	while((s = t->readLine()) != "") {
		if (!seencpu) {
			if (s.contains("cpu"))
				seencpu = true;
			else
				continue;
		}
		if (s.contains("boot device") ||
			s.contains("WARNING: old BSD partition ID!"))
			break;

		if (!filter || s.contains(filter)) {
			if (func) {
				func(lBox, s, &opaque, false);
			}
			else {
				lBox->insertItem(s);
			}
			found = true;
		}
	}
	if (func) {
		func(lBox, s, &opaque, true);
	}
	lBox->setAutoUpdate(true);
	lBox->repaint();

	delete t;
	if (pipe) {
		pclose(pipe);
	}
	else {
		dmesg->close();
		delete dmesg;
	}

	return found;
}

void AddIRQLine(KTabListBox *lBox, QString s, void **opaque, bool ending)
{
	QStrList *strlist = (QStrList *) *opaque;
	const char *str;
	int pos, irqnum=0;

	if (!strlist) {
		strlist = new QStrList();
		*opaque = (void *) strlist;
	}
	if (ending) {
		str = strlist->first();
		for(;str; str = strlist->next()) {
			lBox->insertItem(str);
		}
		delete strlist;
		return;
	}

	pos = s.find(" irq ");
	irqnum = (pos < 0) ? 0 : atoi(&(((const char *)s)[pos+5]));
	if (irqnum) {
		s.sprintf("%02d%s", irqnum, (const char *)s);
	}
	else {
		s.sprintf("??%s", (const char *)s);
	}
	strlist->inSort(s);
}

bool GetInfo_IRQ (KTabListBox *lBox)
{
	lBox->setNumCols(2);
	lBox->setSeparator('');
	lBox->setColumn(0, i18n("IRQ"), 150);
	lBox->setColumn(1, i18n("Device"));
	(void) GetDmesgInfo(lBox, " irq ", AddIRQLine);
	return true;
}

bool GetInfo_DMA (KTabListBox *)
{
  return FALSE;
}

bool GetInfo_PCI (KTabListBox *lbox)
{
	if (!GetDmesgInfo(lbox, "at pci", NULL))
		lbox->insertItem(i18n("No PCI devices found."));
	return true;
}

bool GetInfo_IO_Ports (KTabListBox *lbox)
{
	if (!GetDmesgInfo(lbox, "port 0x", NULL))
		lbox->insertItem(i18n("No device using I/O ports found."));
	return true;
}

bool GetInfo_Sound (KTabListBox *lbox)
{
	if (!GetDmesgInfo(lbox, "audio", NULL))
		lbox->insertItem(i18n("No audio devices found."));
	return true;
}

bool GetInfo_Devices (KTabListBox *lBox)
{
	(void) GetDmesgInfo(lBox, NULL, NULL);
	return true;
}

bool GetInfo_SCSI (KTabListBox *lbox)
{
	if (!GetDmesgInfo(lbox, "scsibus", NULL))
		lbox->insertItem(i18n("No SCSI devices found."));
	return true;
}

bool GetInfo_Partitions (KTabListBox *lbox)
{
	int maxwidth[4]={0,0,0};

	QFontMetrics fm(lbox->tableFont());
	QString s;
	char *line, *orig_line;
	const char *device, *mountpoint, *type, *flags;
	FILE *pipe = popen("/sbin/mount", "r");
	QTextStream *t;

	if (!pipe) {
		kdebug(KDEBUG_ERROR, 0, i18n("Ahh couldn't run /sbin/mount!"));
		return false;
	}
	t = new QTextStream(pipe, IO_ReadOnly);

	lbox->setNumCols(4);
	lbox->setSeparator(';');

	maxwidth[0]=fm.width(i18n("Device"));
	lbox->setColumn(0, i18n("Device"), maxwidth[0]+2);

	maxwidth[1]=fm.width(i18n("Mount Point"));
	lbox->setColumn(1, i18n("Mount Point"), maxwidth[1]+2);

	lbox->setColumn(2, i18n("FS Type"));
	lbox->setColumn(2, i18n("FS Type"), maxwidth[2]+2);

	maxwidth[3]=fm.width(i18n("Mount Options"));
	lbox->setColumn(3, i18n("Mount Options"));


	while ((s = t->readLine()) != "") {
		orig_line = line = strdup(s);

		device = strsep(&line, " ");
		if (fm.width(device) > maxwidth[0]) {
			maxwidth[0]=fm.width(device);
			lbox->setColumnWidth(0, maxwidth[0]+10);
		}

		(void) strsep(&line, " "); // cosume word "on"
		mountpoint = strsep(&line, " ");
		if (fm.width(mountpoint) > maxwidth[1]) {
			maxwidth[1]=fm.width(mountpoint);
			lbox->setColumnWidth(1, maxwidth[1]+10);
		}

		(void) strsep(&line, " "); // cosume word "type"
		type = strsep(&line, " ");
		if (fm.width(type) > maxwidth[2]) {
			maxwidth[2]=fm.width(type);
			lbox->setColumnWidth(2, maxwidth[2]+10);
		}

		flags = line;

		s.sprintf("%s;%s;%s;%s", device, mountpoint, type, flags);
		lbox->insertItem(s);
		free(orig_line);
	}

	delete t;
	pclose(pipe);
	return true;
}

bool GetInfo_XServer_and_Video (KTabListBox *lBox)
{
	return GetInfo_XServer_Generic( lBox );
}

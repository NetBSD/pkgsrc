# $NetBSD: Makefile,v 1.1.1.1 1998/11/04 07:57:25 garbled Exp $
#

DISTNAME=		Gtk-0.4
PKGNAME=		p5-gtk-0.4
CATEGORIES=		x11 perl5
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/perl/

MAINTAINER=		root@garbled.net

DEPENDS+=		gtk+-1.1.2:../../x11/gtk

USE_PERL5=		yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.11 1999/10/23 00:05:18 tron Exp $
#

DISTNAME=		Gtk-0.5120
PKGNAME=		p5-gtk-0.5120
CATEGORIES=		x11 perl5
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/perl/

MAINTAINER=		root@garbled.net

DEPENDS+=		gtk+-1.2.*:../../x11/gtk

USE_PERL5=		yes
USE_X11=		yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"

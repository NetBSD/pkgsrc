# $NetBSD: Makefile,v 1.2 2004/04/19 17:53:39 xtraeme Exp $

DISTNAME=	Gtk2-1.042
PKGNAME=	p5-gtk2-1.042
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings for GTK+ 2.0

DEPENDS+=	p5-ExtUtils-Depends>=0.2:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.03:../../devel/p5-ExtUtils-PkgConfig

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes

PERL5_REQD=	5.8
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Gtk2/.packlist

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

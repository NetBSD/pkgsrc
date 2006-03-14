# $NetBSD: Makefile,v 1.7 2006/03/14 16:00:42 jlam Exp $

DISTNAME=      	Kwiki-Icons-Gnome-0.14
PKGNAME=       	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki GNOME icons plugin

DEPENDS+=	p5-Kwiki>=0.34:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Icons/Gnome/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

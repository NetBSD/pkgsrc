# $NetBSD: Makefile,v 1.20 2008/06/20 01:09:42 joerg Exp $
#

NAME=			CGI-Lite-2.02
DISTNAME=	${NAME}
PKGNAME=	p5-${NAME}
SVR4_PKGNAME=		p5cgl
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		bad@NetBSD.org
COMMENT=		Simple perl5 module for writing forms-based CGI programs

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/CGI/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

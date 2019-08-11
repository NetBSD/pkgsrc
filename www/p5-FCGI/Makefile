# $NetBSD: Makefile,v 1.42 2019/08/11 13:24:36 wiz Exp $

DISTNAME=	FCGI-0.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.fastcgi.com/
COMMENT=	Perl5 library for FastCGI, a fast startup alternative to CGI

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

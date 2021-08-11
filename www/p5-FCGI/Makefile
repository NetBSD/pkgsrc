# $NetBSD: Makefile,v 1.46 2021/08/11 12:38:41 wen Exp $

DISTNAME=	FCGI-0.82
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.fastcgi.com/
COMMENT=	Perl5 library for FastCGI, a fast startup alternative to CGI

TEST_DEPENDS=	p5-FCGI-Client>=0:../../www/p5-FCGI-Client

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

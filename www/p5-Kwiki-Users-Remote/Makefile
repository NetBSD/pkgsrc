# $NetBSD: Makefile,v 1.1.1.1 2006/01/31 20:12:41 jschauma Exp $

DISTNAME=      	Kwiki-Users-Remote-0.04
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to automatically set user name from HTTP authentication

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Users/Remote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

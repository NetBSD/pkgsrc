# $NetBSD: Makefile,v 1.23 2023/07/06 09:42:46 wiz Exp $

DISTNAME=	Kwiki-Users-Remote-0.04
PKGREVISION=	16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to automatically set user name from HTTP authentication

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki
DEPENDS+=	p5-Kwiki-UserName>=0.14:../../www/p5-Kwiki-UserName

PERL5_PACKLIST=		auto/Kwiki/Users/Remote/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

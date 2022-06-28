# $NetBSD: Makefile,v 1.20 2022/06/28 11:37:34 wiz Exp $

DISTNAME=	Kwiki-Simple-Server-HTTP-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Kwiki-Simple-Server-HTTP
COMMENT=	Kwiki plugin to start a standalone Kwiki HTTP server

DEPENDS+=	p5-HTTP-Server-Simple-Kwiki-[0-9]*:../../www/p5-HTTP-Server-Simple-Kwiki
DEPENDS+=	p5-Kwiki>=0.37:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Simple/Server/HTTP/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

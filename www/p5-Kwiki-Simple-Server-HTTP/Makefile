# $NetBSD: Makefile,v 1.11 2015/06/12 10:52:06 wiz Exp $

DISTNAME=	Kwiki-Simple-Server-HTTP-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Kwiki-Simple-Server-HTTP/
COMMENT=	Kwiki plugin to start a standalone Kwiki HTTP server

DEPENDS+=	p5-HTTP-Server-Simple-Kwiki-[0-9]*:../../www/p5-HTTP-Server-Simple-Kwiki
DEPENDS+=	p5-Kwiki>=0.37:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Simple/Server/HTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

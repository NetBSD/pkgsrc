# $NetBSD: Makefile,v 1.14 2017/06/05 14:25:23 ryoon Exp $

DISTNAME=	HTTP-Server-Simple-Kwiki-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple-Kwiki/
COMMENT=	Standalone HTTP server for Kwiki

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTTP/Server/Simple/Kwiki/.packlist

DEPENDS+=	p5-HTTP-Server-Simple-Static-[0-9]*:../../www/p5-HTTP-Server-Simple-Static
DEPENDS+=	p5-IO-Capture-[0-9]*:../../devel/p5-IO-Capture
DEPENDS+=	p5-Kwiki-[0-9]*:../../www/p5-Kwiki

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

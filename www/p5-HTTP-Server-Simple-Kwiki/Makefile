# $NetBSD: Makefile,v 1.1.1.1 2006/05/02 04:11:58 jlam Exp $

DISTNAME=	HTTP-Server-Simple-Kwiki-0.29
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple-Kwiki/
COMMENT=	standalone HTTP server for Kwiki

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTTP/Server/Simple/Kwiki/.packlist

DEPENDS+=	p5-HTTP-Server-Simple-[0-9]*:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-IO-Capture-[0-9]*:../../devel/p5-IO-Capture
DEPENDS+=	p5-Kwiki-[0-9]*:../../www/p5-Kwiki

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

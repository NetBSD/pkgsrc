# $NetBSD: Makefile,v 1.1.1.1 2006/02/07 23:27:56 seb Exp $
#

DISTNAME=	HTTP-Server-Simple-Mason-0.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hsm
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple-Mason/
COMMENT=	Perl5 module providing a simple mason server

PERL5_PACKLIST=		auto/HTTP/Server/Simple/Mason/.packlist

DEPENDS+=	p5-HTML-Mason>=1.25:../../www/p5-HTML-Mason
DEPENDS+=	p5-HTTP-Server-Simple>=0.04:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-Hook-LexWrap-[0-9]*:../../devel/p5-Hook-LexWrap

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

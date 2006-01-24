# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:49 wiz Exp $
#

DISTNAME=	HTTP-DAV-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5htd
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://webdav.org/perldav/
COMMENT=	HTTP::DAV interface and 'dave'

DEPENDS+=       p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM

PERL5_PACKLIST=		auto/HTTP/DAV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

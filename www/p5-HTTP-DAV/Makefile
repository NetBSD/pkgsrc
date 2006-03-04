# $NetBSD: Makefile,v 1.12 2006/03/04 21:31:02 jlam Exp $
#

DISTNAME=	HTTP-DAV-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5htd
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webdav.org/perldav/
COMMENT=	HTTP::DAV interface and 'dave'

DEPENDS+=       p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM

PERL5_PACKLIST=		auto/HTTP/DAV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2003/05/03 16:58:32 cyber Exp $
#

DISTNAME=	HTTP-DAV-0.31
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5htd
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://webdav.org/perldav/
COMMENT=	HTTP::DAV interface and 'dave'

DEPENDS+=       p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTTP/DAV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

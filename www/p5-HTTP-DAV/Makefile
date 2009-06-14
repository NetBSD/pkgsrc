# $NetBSD: Makefile,v 1.17 2009/06/14 20:25:50 sno Exp $
#

DISTNAME=	HTTP-DAV-0.38
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5htd
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webdav.org/perldav/
#HOMEPAGE=	http://search.cpan.org/dist/HTTP-DAV/
COMMENT=	HTTP::DAV interface and 'dave'
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww
DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM

PERL5_PACKLIST=		auto/HTTP/DAV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

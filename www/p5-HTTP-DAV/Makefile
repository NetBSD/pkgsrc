# $NetBSD: Makefile,v 1.22 2011/08/14 16:05:57 obache Exp $
#

DISTNAME=	HTTP-DAV-0.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5htd
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webdav.org/perldav/
#HOMEPAGE=	http://search.cpan.org/dist/HTTP-DAV/
COMMENT=	HTTP::DAV interface and 'dave'
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=	bin/dave

DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww
DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM

PERL5_PACKLIST=		auto/HTTP/DAV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

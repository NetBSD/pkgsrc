# $NetBSD: Makefile,v 1.22 2011/08/14 16:05:58 obache Exp $
#

DISTNAME=	HTTP-Request-Form-0.952
PKGNAME=	p5-${DISTNAME:S/952/9.5.2/}
PKGREVISION=	4
SVR4_PKGNAME=	p5htt
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Request-Form/
COMMENT=	Construct HTTP::Request objects for form processing

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

PERL5_PACKLIST=		auto/HTTP/Request/Form/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

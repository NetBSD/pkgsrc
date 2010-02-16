# $NetBSD: Makefile,v 1.11 2010/02/16 15:22:45 sno Exp $
#

DISTNAME=	CGI-Kwiki-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5ckw
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Quickie Wiki that's not too Tricky

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-Simple>=0.47:../../devel/p5-Test-Simple
DEPENDS+=	p5-Locale-Maketext>=1.08:../../misc/p5-Locale-Maketext

PERL5_PACKLIST=		auto/CGI-Kwiki/.packlist

.include "../../mk/bsd.prefs.mk"

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

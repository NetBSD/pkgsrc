# $NetBSD: Makefile,v 1.18 2001/11/26 15:02:32 jlam Exp $
#

DISTNAME=		mod_perl-1.25
PKGNAME=		ap-perl-1.25nb1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/} \
			http://perl.apache.org/dist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

DEPENDS+=		${BUILDLINK_DEPENDS.apache}:../../www/apache
DEPENDS+=		libperl>=${LIBPERL5_REQD}:../../lang/libperl
DEPENDS+=		p5-BSD-Resource>=1.10:../../devel/p5-BSD-Resource

USE_BUILDLINK_ONLY=	YES
LIBPERL5_REQD=		${PERL5_REQD}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/mod_perl/.packlist

REPLACE_BUILDLINK=	blib/lib/Apache/MyConfig.pm
REPLACE_BUILDLINK_SED=	-e "s|${APXS}|${PREFIX}/sbin/apxs|g"

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}
MAKE_PARAMS+=		EVERYTHING=1

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/manual/mod
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
		${PREFIX}/share/httpd/htdocs/manual/mod

.include "../../lang/perl5/buildlink.mk"
.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

.if exists(${PERL5_ARCHLIB}/DynaLoader_pic.o)
MAKE_ENV+=		DYNALOADER_OBJ_PIC="${PERL5_ARCHLIB}/DynaLoader_pic.o"
.endif
